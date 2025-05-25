#include "BaseObject.h"
#include <string.h>
#include <stdio.h>

void BaseObject::nhapId(const char* id) {
	strcpy_s(this->id, id);
}

const char* BaseObject::getId() {
	return id;
}

void BaseObject::docFile(FILE* file) {
	if (fgets(id, MAX_LEN, file) != NULL) {
		size_t len = strlen(id);

		if (len > 0 && id[len - 1] == '\n') {
			id[len - 1] = '\0';
		}
	}
}

