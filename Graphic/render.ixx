module;
#include <d3d11.h>
#include <DirectXMath.h>
#include <wrl/client.h>

export module graphic.render;

template <typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

import std;
import graphic.shader;

// ���_�\����
export struct Vertex {
  DirectX::XMFLOAT3 position; // ���_���W
  DirectX::XMFLOAT4 color;    // �F
  DirectX::XMFLOAT2 uv;       // �e�N�X�`���[
};

export class Renderer {
private:
  ComPtr<ID3D11Device> device_ = nullptr;
  ComPtr<ID3D11DeviceContext> device_context_ = nullptr;
  std::shared_ptr<ShaderManager> shader_manager_ = nullptr;

  ComPtr<ID3D11Buffer> vertex_buffer_ = nullptr; // ���_�o�b�t�@

  int vertex_num_ = 0;

public:
  Renderer(ID3D11Device* pDevice, ID3D11DeviceContext* pContext,
           const std::shared_ptr<ShaderManager>& shader_manager, int vertex_num = 4);

  void Draw();
};
