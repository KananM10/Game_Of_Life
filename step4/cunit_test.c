#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/Cunit.h>

#include <game.h>

void test_neighbours_circular(void){
    
}

int main(){
    if(CUE != CU_initialize_registry())
    return CU_get_error();

    CU_psuite pS1 = CU_add_suite("Testing smth(function .h)", NULL, NULL);
    CU_ADD_TEST(pS1, "nazvanie functii kotoruyu proverayu bez kovychek");
    //




    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    return CU_get_number_of_failures();

    CU_cleanup_registry();
}