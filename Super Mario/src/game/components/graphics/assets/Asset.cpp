#include "stdafx.h"
#include "Asset.h"
#include <SDL.h>


Asset::Asset(LTexture* texture): m_Texture(texture), m_Start(0), m_Current(0), m_End(0), m_size(0), m_Shapes(NULL)
{
	
}

Asset::~Asset()
{
}

LTexture* Asset::GetTexture()
{
	return m_Texture;
}

ShapeRec& Asset::GetShape(int shape)
{
	return (shape < m_size && shape >= 0)? m_Shapes[shape] : m_Shapes[0];
}

int& Asset::GetSize()
{
	return m_size;
}

bool Asset::SetStart(int start)
{
	if (start < 0 || start >= m_size || start > m_End) return false;
	m_Start = start;
	return true;
}

bool Asset::SetCurrent(int current)
{
	if (current < 0 || current >= m_size) return false;
	m_Current = current;
	m_Texture->CutTexture(m_Shapes[m_Current]);
	return true;
}

bool Asset::SetEnd(int end)
{
	if (end < 0 || end >= m_size || end < m_Start) return false;
	m_End = end;
	return true;
}

ShapeRec& Asset::NextShape()
{
	m_Current = (m_Current + 1 < m_size) ? m_Current + 1 : 0;
	m_Texture->CutTexture(m_Shapes[m_Current]);
	return m_Shapes[m_Current];

}

bool Asset::Render(SDL_Renderer* renderer)
{
	m_Texture->Render(renderer);
	return true;
}
