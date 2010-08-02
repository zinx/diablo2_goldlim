#include "common.h"
#include "d2.h"
#include "d2_112a.h"

int patch_d2(void)
{
	return patch_112a();
}

void unpatch_d2(void)
{
	unpatch_112a();
}
