#include <string.h>

#include <uriparser/Uri.h>

int main(void) {
  const char *error_position = NULL;
  UriUriA uri;
  int valid;

  if (uriParseSingleUriA(
          &uri, "https://example.com/path?query=value", &error_position)
      != URI_SUCCESS) {
    return 1;
  }

  valid = uri.scheme.first != NULL
      && uri.scheme.afterLast - uri.scheme.first == 5
      && strncmp(uri.scheme.first, "https", 5) == 0
      && uri.hostText.first != NULL
      && uri.hostText.afterLast - uri.hostText.first == 11
      && strncmp(uri.hostText.first, "example.com", 11) == 0;

  uriFreeUriMembersA(&uri);
  return valid ? 0 : 1;
}
