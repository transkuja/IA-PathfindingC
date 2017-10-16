/***************************************************/
/* Nom:	Component.h
/* Description: Component
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __Component_H_
#define __Component_H_

namespace crea
{

	class CREAENGINE_API Component
	{
	protected:
		// Name
		string m_szName;

		Entity* m_pEntity; // The entity this component is attached to.

	public:
		Component();
		virtual ~Component();

		inline bool hasName(string& _szName) { return (m_szName == _szName); }
		inline void setName(string& _szName) { m_szName = _szName; }

		inline void setEntity(Entity* _pEntity) { m_pEntity = _pEntity; }
		inline Entity* getEntity() { return m_pEntity; }

		virtual bool init() = 0;
		virtual bool update() = 0;
		virtual bool draw() = 0;
		virtual bool quit() = 0;

	};

} // namespace crea

#endif
