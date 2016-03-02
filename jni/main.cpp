#include <Substrate.h>
#include <dlfcn.h>
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <random>

#include "mcpe/BlockTessellator.h"

bool (*_tessellateInWorld)(BlockTessellator*, Block&, const BlockPos&, bool);
bool tessellateInWorld(BlockTessellator* self, Block& block, const BlockPos& pos, bool b) {
	/*if(&block == Block::mBlocks[46]) return self->tessellateWireInWorld(block, pos);
	else */return _tessellateInWorld(self, block, pos, b);
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	MSHookFunction((void*) &BlockTessellator::tessellateInWorld, (void*) &tessellateInWorld, (void**) &_tessellateInWorld);
	return JNI_VERSION_1_2;
}
