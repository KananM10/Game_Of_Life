#include <stdio.h>
// #include <stdbool.h>
// #include <math.h>

#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>

#include "./game/game.h"

void test_check_neighb_circular(){
    grid g;
    init_grid_from_file("../grids/grid4.txt", &g);

    CU_ASSERT_TRUE(0 == check_neighbours_circular(1,5,g));   
    CU_ASSERT_TRUE(0 == check_neighbours_circular(6,2,g));    
    CU_ASSERT_TRUE(2 == check_neighbours_circular(5,1,g));  
    CU_ASSERT_TRUE(5 == check_neighbours_circular(3,2,g));     
    CU_ASSERT_FALSE(9 == check_neighbours_circular(7,2,g));
    CU_ASSERT_TRUE(3 == check_neighbours_circular(4,0,g));
}

void test_check_neighb_clipped(void){
    grid g;
    init_grid_from_file("../grids/grid4.txt", &g);

    CU_ASSERT_TRUE(5 == check_neighbours_clipped(3,2,g));
    CU_ASSERT_TRUE(2 == check_neighbours_clipped(5,3,g));
    CU_ASSERT_TRUE(2 == check_neighbours_clipped(4,7,g));
}

int main(){
    if(CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();   

    CU_pSuite pS1 = CU_add_suite("Testing test_check_neighb_circular", NULL, NULL);
    CU_ADD_TEST(pS1, test_check_neighb_circular); 

    CU_pSuite pS2 = CU_add_suite("Testing test_check_neighb_clipped", NULL, NULL);
    CU_ADD_TEST(pS2, test_check_neighb_clipped);   

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    printf("\n\n");
    printf("Number of suites run: %d\n", CU_get_number_of_suites_run());
    printf("Number of suites failed: %d\n", CU_get_number_of_suites_failed());
    printf("Number of tests run: %d\n", CU_get_number_of_tests_run());
    printf("Number of tests failed: %d\n", CU_get_number_of_tests_failed());
    printf("Number of asserts done: %d\n", CU_get_number_of_asserts());
    printf("Number of asserts successful: %d\n", CU_get_number_of_successes());
    printf("Number of asserts failed: %d\n", CU_get_number_of_failures());

    CU_cleanup_registry();
    return CU_get_error();
}
