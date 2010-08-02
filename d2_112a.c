#include "common.h"
#include <patch.h>

#include "d2.h"
#include "goldlim.h"

#define HEADER "d2_112a_common.h"
#define NAME d2common_112a
#include "declPatch.h"

int patch_112a(void)
{
	return patch_d2common_112a();
}

void unpatch_112a(void)
{
	unpatch_d2common_112a();
}
