#pragma once

#include "../game.hpp"
#include "../render/renderer.hpp"
#include "../render/mesh.hpp"
#include "textures.hpp"
#include "meshes.hpp"

namespace SMOBA
{
	namespace ASSETS
	{
		void Load_Assets(ViewportInfo& viewport);
		void Unload_Assets();
		Texture2D* Get_Texture(ID assetID);
		Mesh* Get_Mesh(ID assetID);
		extern Array<Texture2D> Textures;
		extern Array<Mesh> Meshes;
	}
}
