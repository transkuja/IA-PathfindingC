/***************************************************/
/* Nom:	SceneManager.h
/* Description: SceneManager
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __SceneManager_H_
#define __SceneManager_H_

namespace crea
{
	class Scene;

	class CREAENGINE_API SceneManager
	{
		SceneManager();

	protected: 
		Scene* m_pCurrentScene;

	public:
		virtual ~SceneManager();

		static SceneManager* getSingleton();

		bool update();

		bool draw();

		void setScene(Scene* s);
	};

} // namespace crea

#endif
