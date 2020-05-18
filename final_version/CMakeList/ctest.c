#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/Cunit.h>

#include <game.h>

void test_init_grid(grid *g){
    int i = 0;
    int j = 2;
    int n = 2;
    int s = 50;
    int alive = 5;

    CU_ASSERT_TRUE(set_alive(n, j, *g));
}

int main(){
    if(CUE != CU_initialize_registry())
    return CU_get_error();

    CU_psuite pS1 = CU_add_suite("Testing test_init_grid", NULL, NULL);
    CU_ADD_TEST(pS1, test_init_grid);
    //




    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    return CU_get_number_of_failures();

    CU_cleanup_registry();
}