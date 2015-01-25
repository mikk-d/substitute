#pragma once
#include "dis.h"
#define MAX_JUMP_PATCH_SIZE 8
#define MAX_REWRITTEN_SIZE (12 * 4) /* actually should be less */

static inline int jump_patch_size(uintptr_t pc, uintptr_t dpc,
                                  struct arch_dis_ctx arch) {
    return 8;
}

static inline void make_jump_patch(void **codep, uintptr_t pc, uintptr_t dpc,
                                   struct arch_dis_ctx arch) {
    if (arch.pc_low_bit)
        op32(codep, 0xf000f8df);
    else
        op32(codep, 0xe51ff004);
    op32(codep, (uint32_t) pc);
}
