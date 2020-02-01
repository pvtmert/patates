/*bin/echo
FILE="$0.exe"
trap "rm -f '$FILE'" EXIT
cc -I../inc -o "$FILE" -c "$0"
exit
*/

#include <stdio.h>

#include "file.h"

__attribute__((constructor)) static void
construct(void) {
	fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
	return;
}

__attribute__((destructor)) static void destruct(void) {
	fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
	return;
}

void
file_init(void) {
	return;
}

size_t
file_size(const char *name) {
	FILE *fp = fopen(name, "rb");
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	fclose(fp);
	return size;
}
