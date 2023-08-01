#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

int main() {
  char *libplug_filename = "libplug.so";
  char commad[256];

  while (1) {
    printf("reloder: ");
    scanf("%s", commad);
    printf("\n");

    if (!strcmp(commad, "quit")) {
      return 0;
    }

    if (!strcmp(commad, "reload")) {
      void *libplug_handel = dlopen(libplug_filename, RTLD_NOW);
      if (!libplug_handel) {
        fprintf(stderr, "dlopne %s\n", dlerror());
        return 1;
      }

      void (*hello_plug)(void) = dlsym(libplug_handel, "hello_plug");
      if (!libplug_handel) {
        fprintf(stderr, "dlsym %s\n", dlerror());
        return 1;
      }

      hello_plug();

      dlclose(libplug_handel);
    }

    memset(commad, '\0', 256);
  }

  return 0;
}
