#include "path_extractor.h"
#include <direct.h>

// https://darkdevilness.tistory.com/18 Âü°í

std::string PathExtractor()
{
	if (_waccess(L"image", 0) == -1) {
		exit(0);
	}

	char curDir[1000];
	_getcwd(curDir, 1000);

	return std::string(curDir) + "\\image\\";
}
