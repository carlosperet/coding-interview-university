#include "hash_map_tests.h"
#include <string.h>

const size_t kTableSize = 100;
char kDummy[8] = "<dummy>";

void run_all_tests(void) {
  test_exists();
  test_add_get();
  test_add_remove();
}

void test_exists(void) {
  hash_table* states = create_table(kTableSize);

  assert(exists(states, "Texas") == false);

  key_value tx = {"Texas", "Austin", NULL};
  add(states, "Texas", &tx);

  assert(exists(states, "Texas") == true);

  destroy_table(states);
}

void test_add_get(void) {
  hash_table* states = create_table(kTableSize);

  key_value la = {"Louisiana", "Baton Rouge", NULL};
  add(states, "Louisiana", &la);

  key_value me = {"Maine", "Augusta", NULL};
  add(states, "Maine", &me);

  key_value* capital1 = get(states, "Louisiana");
  assert(strcmp(capital1->value, "Baton Rouge") == 0);

  // add LA again, with new capital
  key_value la2 = {"Louisiana", "New Orleans", NULL};
  add(states, "Louisiana", &la2);

  // now capital should be Nawlins
  key_value* capital2 = get(states, "Louisiana");
  assert(strcmp(capital2->value, "New Orleans") == 0);
  Print_Debug(states);

  destroy_table(states);
}

void test_add_remove(void) {
  hash_table* states = create_table(kTableSize);

  key_value ca = {"California", "Sacramento", NULL};
  add(states, "California", &ca);

  assert(exists(states, "California") == true);

  delete(states, "California");

  assert(exists(states, "California") == false);

  destroy_table(states);
}
