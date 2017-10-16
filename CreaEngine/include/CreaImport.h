#ifndef _CREAIMPORT_H
#define _CREAIMPORT_H

namespace crea
{

#   ifdef CREAENGINE_EXPORTS
#       define CREAENGINE_API __declspec(dllexport)
#   else
#       define CREAENGINE_API __declspec(dllimport)
#   endif

} // namespace LibMath


#include "Core\GameManager.h"
#include "Core\SceneManager.h"
#include "Core\EntityManager.h"
#include "Core\Entity.h"
#include "Core\Scene.h"
#include "Core\Math.h"
#include "Data\DataManager.h"
#include "Data\Map.h"
#include "Graphics\Color.h"
#include "Graphics\Font.h"
#include "Graphics\Text.h"
#include "Graphics\Texture.h"
#include "Graphics\Sprite.h"
#include "Graphics\SpriteRenderer.h"
#include "Graphics\TextRenderer.h"
#include "Graphics\MapRenderer.h"

#   endif // _COOLINIMPORT_H