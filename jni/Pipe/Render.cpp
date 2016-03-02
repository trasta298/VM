#include "mcpe/BlockTessellator.h"

bool BlockTessellator::tessellatePipeInWorld(Block& tile, BlockPos const& pos){
	Block* block = &tile;
	useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;

	setRenderBounds(0.25, 0.25, 0.25, 0.75, 0.75, 0.75);
	tessellateBlockInWorld(tile, pos);

	Block* a = blockSource->getBlock(x,y+1,z);
	Block* b = blockSource->getBlock(x,y-1,z);
	Block* c = blockSource->getBlock(x+1,y,z);
	Block* d = blockSource->getBlock(x-1,y,z);
	Block* e = blockSource->getBlock(x,y,z+1);
	Block* f = blockSource->getBlock(x,y,z-1);

	if(a==Block::mBlocks[182]||a==Block::mBlocks[202]||a==Block::mBlocks[180]||a==Block::mBlocks[188]){
		setRenderBounds(0.25, 0.75, 0.25, 0.75, 1.00, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(a==Block::mBlocks[54]){
		setRenderBounds(0.25, 0.75, 0.25, 0.75, 1.20, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(b==Block::mBlocks[182]||b==Block::mBlocks[202]||b==Block::mBlocks[180]||b==Block::mBlocks[188]){
		setRenderBounds(0.25, 0.00, 0.25, 0.75, 0.25, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(b==Block::mBlocks[54]){
		setRenderBounds(0.25,-0.20, 0.25, 0.75, 0.25, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(c==Block::mBlocks[182]||c==Block::mBlocks[202]||c==Block::mBlocks[180]||c==Block::mBlocks[188]){
		setRenderBounds(0.75, 0.25, 0.25, 1.00, 0.75, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(c==Block::mBlocks[54]){
		setRenderBounds(0.75, 0.25, 0.25, 1.20, 0.75, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(d==Block::mBlocks[182]||d==Block::mBlocks[202]||d==Block::mBlocks[180]||d==Block::mBlocks[188]){
		setRenderBounds(0.0, 0.25, 0.25, 0.25, 0.75, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(d==Block::mBlocks[54]){
		setRenderBounds(-0.20, 0.25, 0.25, 0.25, 0.75, 0.75);
		tessellateBlockInWorld(tile, pos);
	}
	if(e==Block::mBlocks[182]||e==Block::mBlocks[202]||e==Block::mBlocks[180]||e==Block::mBlocks[188]){
		setRenderBounds(0.25, 0.25, 0.25, 0.75, 0.75, 1.00);
		tessellateBlockInWorld(tile, pos);
	}
	if(e==Block::mBlocks[54]){
		setRenderBounds(0.25, 0.25, 0.25, 0.75, 0.75, 1.20);
		tessellateBlockInWorld(tile, pos);
	}
	if(f==Block::mBlocks[182]||f==Block::mBlocks[202]||f==Block::mBlocks[180]||f==Block::mBlocks[188]){
		setRenderBounds(0.25, 0.25, 0.00, 0.75, 0.75, 0.25);
		tessellateBlockInWorld(tile, pos);
	}
	if(f==Block::mBlocks[54]){
		setRenderBounds(0.25, 0.25,-0.20, 0.75, 0.75, 0.25);
		tessellateBlockInWorld(tile, pos);
	}
}

bool BlockTessellator::tessellateWireInWorld(Block& tile, BlockPos const& pos){
	Block* block = &tile;
	useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;


	setRenderBounds(0.35, 0.35, 0.35, 0.65, 0.65, 0.65);
	tessellateBlockInWorld(tile, pos);

	//forcedUV = block->getTexture(1,0);

	Block* a = blockSource->getBlock(x,y+1,z);
	Block* b = blockSource->getBlock(x,y-1,z);
	Block* c = blockSource->getBlock(x+1,y,z);
	Block* d = blockSource->getBlock(x-1,y,z);
	Block* e = blockSource->getBlock(x,y,z+1);
	Block* f = blockSource->getBlock(x,y,z-1);

	if(a==Block::mBlocks[177]||a==Block::mBlocks[181]||a==Block::mBlocks[176]){
		setRenderBounds(0.35, 0.65, 0.35, 0.65, 1.00, 0.65);
		tessellateBlockInWorld(tile, pos);
	}

	if(b==Block::mBlocks[177]||b==Block::mBlocks[181]||b==Block::mBlocks[176]){
		setRenderBounds(0.35, 0.00, 0.35, 0.65, 0.35, 0.65);
		tessellateBlockInWorld(tile, pos);
	}

	if(c==Block::mBlocks[177]||c==Block::mBlocks[181]||c==Block::mBlocks[176]){
		setRenderBounds(0.65, 0.35, 0.35, 1.00, 0.65, 0.65);
		tessellateBlockInWorld(tile, pos);
	}

	if(d==Block::mBlocks[177]||d==Block::mBlocks[181]||d==Block::mBlocks[176]){
		setRenderBounds(0.0, 0.35, 0.35, 0.35, 0.65, 0.65);
		tessellateBlockInWorld(tile, pos);
	}

	if(e==Block::mBlocks[177]||e==Block::mBlocks[181]||e==Block::mBlocks[176]){
		setRenderBounds(0.35, 0.35, 0.35, 0.65, 0.65, 1.00);
		tessellateBlockInWorld(tile, pos);
	}

	if(f==Block::mBlocks[177]||f==Block::mBlocks[181]||f==Block::mBlocks[176]){
		setRenderBounds(0.35, 0.35, 0.00, 0.65, 0.65, 0.35);
		tessellateBlockInWorld(tile, pos);
	}

	//forcedUV = block->getTexture(1,0);
	useForcedUV = false;
}


