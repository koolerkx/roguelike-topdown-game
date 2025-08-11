module;
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

export module application;

import std;
import app.timer;
import graphic.direct3D;
import game.scene_manager;

#if defined(DEBUG) || defined(_DEBUG)
import graphic.debug;
#endif

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

  std::unique_ptr<SceneManager> scene_manager_ = nullptr;

#if defined(DEBUG) || defined(_DEBUG)
  std::unique_ptr<DebugManager> debug_manager_ = nullptr;
#endif

  std::unique_ptr<TimerUpdater> timer_updater_ = nullptr;

  void OnUpdate(float delta_time);
  void OnFixedUpdate(float delta_time);

public:
  static Application& Instance();

  bool Init();      /// ������
  void Run(); /// ���[�v�N��

  /// �㏈��
  void Terminate() const;
  static SIZE GetWindowSize();
  ~Application();
};
