#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char** argv) {
  if (argc > 1 && std::string(argv[1]) == "-d") {
    // By default readline does filename completion. With -d, we disable this
    // by asking readline to just insert the TAB character itself.
    rl_bind_key('\t', rl_insert);
  }

  char* buf;
  while ((buf = readline("flare> ")) != nullptr) {
    if (strlen(buf) > 0) {
      add_history(buf);
    }

    printf("[%s]\n", buf);

    free(buf);
  }

  return 0;
}
