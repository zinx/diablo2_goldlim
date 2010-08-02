#include "common.h"

#include "util.h"

#include "d2.h"
#include "goldlim.h"

#define MOD_NAME "goldlim"
#define AUTHOR "Zinx Verituse <zinx@zenthought.org>"
#define FULL_NAME MOD_NAME " by "AUTHOR" [built @ "__DATE__" "__TIME__"]"

#define INI_NAME MOD_NAME ".ini"

int gold_inv_mul = 80000;
int gold_stash_mul = 200000;

static void goldlim_ini_load(void)
{
	char *value;

	ini_t *ini = ini_load(INI_NAME);
	if (!ini) {
		LOG("No "INI_NAME" found.");
		return;
	}

	value = ini_get_setting(ini, "goldlim", "InventoryMultiplier");
	if (value) gold_inv_mul = strtol(value, NULL, 0);

	value = ini_get_setting(ini, "goldlim", "StashMultiplier");
	if (value) gold_stash_mul = strtol(value, NULL, 0);

	ini_free(ini);
}

WINAPI BOOL DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{
	int ret;
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		goldlim_ini_load();
		ret = patch_d2();
		if (!ret) {
			LOG(FULL_NAME " loaded");
			LOG("    InventoryMultiplier = %d, StashMultiplier = %d", gold_inv_mul, gold_stash_mul);
		} else {
			LOG(FULL_NAME " failed to load (%d)", ret);
		}
		return !ret;
	case DLL_PROCESS_DETACH:
		unpatch_d2();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
