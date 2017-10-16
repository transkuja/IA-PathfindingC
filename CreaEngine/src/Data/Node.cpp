#include "stdafx.h"

#include "Data\Node.h"
#include "Graphics\Sprite.h"

namespace crea
{
	Node::Node()
	{
		m_nTileTerrainId = -1;
		m_nTileCollisionId = -1;
	}

	Node::~Node()
	{
		// Do not delete children, as they are not allocated in Node
	}

	void Node::addChild(Node* _pNode)
	{
		m_pChildren.push_back(_pNode);
	}
	
	bool Node::update()
	{
		return true;
	}

	bool Node::draw()
	{
		return true;
	}

	void Node::clear()
	{
		m_pChildren.clear();
	}

} // namespace crea
