/***************************************************/
/* Nom:	Texture.h
/* Description: Texture
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Texture_H
#define _Texture_H

namespace sf
{
	class Texture;
}
namespace crea
{

	class CREAENGINE_API Texture
	{
	public:
		sf::Texture* m_pTexture;

		Texture();

		~Texture();

		virtual bool loadFromFile(std::string _file);
	};

} // namespace crea

#endif // _Texture_H