#include <cstdlib>
#include <stdio.h>

#include "../game.hpp"
#include "../sAssert.hpp"

namespace SMOBA {

struct gltf_header {
    u32 magic;
    u32 version;
    u32 length;
};

struct gltf_chunk {
    struct {
        u32 length;
        u32 type;
    } header;
    u8 *data;
};

i32 open_gltf(const char* path) {
   FILE* instream = fopen(path, "rb");
   s_assert(instream != 0, "Could not open file!");

   gltf_header header = {};
   fread(&header, sizeof(gltf_header), 1, instream);
   s_assert(header.magic == 0x46546C67, "Not a gltf file!");
   printf("gltf version: %d, size: %d\n", header.version, header.length);

   gltf_chunk json_chunk = {};
   fread(&json_chunk.header, sizeof(json_chunk.header), 1, instream);
   json_chunk.data = (u8*)malloc(sizeof(u8) * json_chunk.header.length);
   fread(json_chunk.data, sizeof(u8) * json_chunk.header.length, 1, instream);
   printf("%s\n", json_chunk.data);


   return 0;
}

}
