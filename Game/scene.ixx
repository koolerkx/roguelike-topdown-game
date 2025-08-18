module;

export module game.scene;
export import game.context;

export class IScene {
public:
  virtual ~IScene() = default;

  /**
   * @brief �V�[���ɓ��鎞��񂾂��Ă�
   */
  virtual void OnEnter(GameContext* ctx) = 0;

  /**
   * @brief �t���[�����ɌĂ�
   */
  virtual void OnUpdate(GameContext* ctx, float delta_time) = 0;

  /**
   * @brief �t���[�����ɌĂ�
   */
  virtual void OnRender(GameContext* ctx) = 0;

  /**
   * @brief �Œ�̕p�x�ɌĂ�
   */
  virtual void OnFixedUpdate(GameContext* ctx, float delta_time) = 0;

  /**
   * @brief �V�[������o�鎞���?���Ă�?
   */
  virtual void OnExit(GameContext* ctx) = 0;
};
