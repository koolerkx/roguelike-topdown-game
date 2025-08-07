module;
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

export module application;

import std;
import graphic.direct3D;

export class Application {
private:
  // �E�B���h�E
  WNDCLASSEX window_class_;
  HWND hwnd_ = nullptr;
  std::shared_ptr<Dx11Wrapper> direct3d_;

  // �Q�[���p�E�B���h�E�̐���
  static void CreateGameWindow(HWND& hwnd, WNDCLASSEX& windowClass);

  // �V���O���g���A�R�s�[�E����֎~
  Application();
  Application(const Application&) = delete;
  void operator=(const Application&) = delete;

public:
  static Application& Instance();

  bool Init();      /// ������
  void Run() const; /// ���[�v�N��

  /// �㏈��
  void Terminate() const;
  static SIZE GetWindowSize();
  ~Application();
};
