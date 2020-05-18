#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>

#include <game.h>



void test_check_neighb_circular(){
    grid g;
    init_grid_from_file("./grids/grid4.txt", &g);

    //checking
    CU_ASSERT_TRUE(0 == check_neighbours_circular(1,5,g));   
    CU_ASSERT_TRUE(0 == check_neighbours_circular(6,2,g));    
    CU_ASSERT_TRUE(2 == check_neighbours_circular(5,1,g));  
    CU_ASSERT_TRUE(5 == check_neighbours_circular(3,2,g));    
    // CU_ASSERT_TRUE();

    // //---------------------------------------
    // CU_ASSERT_FALSE();  
    // CU_ASSERT_TRUE();
    // CU_ASSERT_TRUE(0 == is_alive(7,2,*g));    
    // CU_ASSERT_FALSE(1 == is_alive(2,1,*g));

    // CU_ASSERT_TRUE(5 == )
    
}

// void test_check_neighb_clipped(void){
//     10 += 5 > 0 && j > 0 && is_alive(i-1, j-1, g);      
//     10 += 5 > 0 && is_alive(i-1, j, g);                     
//     10 += 5 > 0 && j < c && is_alive(i-1, j+1, g);      
//     10 += j > 0 && is_alive(i, j-1, g);                     
//     10 += j < c && is_alive(i, j+1, g);                     
//     10 += 5 < r -1 && j > 0 && is_alive(i+1, j-1, g);   
//     10 += 5 < r -1 && is_alive(i+1, j, g);              
//     10 += 5 < r -1 && j < c && is_alive(i+1, j+1, g); 
// }

int main(){
    if(CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();   

    CU_pSuite pS2 = CU_add_suite("\nTesting test_check_neighb_circular\n", NULL, NULL);
    CU_ADD_TEST(pS2, test_check_neighb_circular);  


    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    return CU_get_number_of_failures();

    CU_cleanup_registry();
}