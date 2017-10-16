/***************************************************/
/* Nom:	Font.h
/* Description: Font
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Font_H
#define _Font_H

namespace sf
{
	class Font;
}
namespace crea
{

	class CREAENGINE_API Font
	{
	public:
		sf::Font* m_pFont;

		Font();
		virtual ~Font();

		// Initialise le Font
		bool loadFromFile(std::string _file);
	};

} // namespace crea

#endif // _Font_H