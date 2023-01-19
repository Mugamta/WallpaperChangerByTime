#include "set_desktop_wallpaper.h"

// http://www.poshy.net/55014 Âü°í

void SetDesktopWallPaper(LPCTSTR pszFileName, int nTile)
{

	HKEY hKey;
	static char tile[2];
	long lRet;

	tile[0] = '0' + nTile;
	tile[1] = '\0';

	lRet = ::RegOpenKeyEx(HKEY_CURRENT_USER, L"Control Panel\\desktop", 0, KEY_WRITE | KEY_READ, &hKey);
	::RegSetValueEx(hKey, L"TileWallpaper", 0, REG_SZ, (const unsigned char*)tile, 1);
	::RegCloseKey(hKey);
	::SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)pszFileName, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

}