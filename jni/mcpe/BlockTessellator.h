#pragma once
#include <string>
#include <functional>

class Tessellator;
#include "mcpe/BlockPos.h"
#include "mcpe/Block.h"
#include "mcpe/BlockSource.h"
#include "mcpe/Vec3.h"
#include "mcpe/TextureUVCoordinateSet.h"
#include "mcpe/AABB.h"
#include "mcpe/DataID.h"

class BlockTessellator {
public:

    bool forceOpaque; // 0
    bool mirror; // 1
    BlockSource* blockSource; // 4
    TextureUVCoordinateSet forcedUV; // 8
    bool useForcedUV; // 40
    char filler[88]; // 44
    int rotBottom; // 132
    int rotTop; // 136
    int rotEast; // 140
    int rotWest; // 144
    int rotNorth; // 148
    int rotSouth; // 152
    char filler1[512]; // 156
    Tessellator* tess; // 668
    AABB bounds; // 672

	bool tessellateInWorld(Block&, const BlockPos&, unsigned char, bool);
	bool tessellateBlockInWorld(Block &, const BlockPos&);
	DataID getData(const BlockPos&) const;
	unsigned int getLightColor(const BlockPos&);

	void setRenderBounds(float x1, float y1, float z1, float x2, float y2, float z2) {
		bounds = AABB(x1, y1, z1, x2, y2, z2);
	}

	/*render functions*/
	bool tessellateWireInWorld(Block&, BlockPos const&);
	bool tessellatePipeInWorld(Block&, BlockPos const&);
};