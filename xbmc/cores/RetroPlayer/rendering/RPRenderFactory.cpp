/*
 *      Copyright (C) 2017 Team XBMC
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "RPRenderFactory.h"

using namespace KODI;
using namespace RETRO;

RPCreateRenderer CRPRendererFactory::m_renderCreator = nullptr;

CRPBaseRenderer* CRPRendererFactory::CreateRenderer()
{
  if (m_renderCreator != nullptr)
    return m_renderCreator();

  return nullptr;
}

void CRPRendererFactory::RegisterRenderer(RPCreateRenderer createFunc)
{
  m_renderCreator = createFunc;
}

void CRPRendererFactory::ClearRenderer()
{
  m_renderCreator = nullptr;
}