#ifndef browseFiles
#define browseFiles
#include <shlobj.h>
#include <string>

int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData);
std::string BrowseFolder(std::string saved_path);

#endif