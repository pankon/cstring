#include <stdio.h>
#include "cstring.h"

int main(void) {
    decl_static_cstring_from_string(string, "hi");
    decl_static_cstring(other, 10);
    decl_static_cstring(other_larger, 100);
    decl_static_cstring(other_much_larger, 10000);

    printf("data: %s\n", c_str(string));

    ptr_c_strcpy(&other, &string);
    printf("other data: %s\n", c_str(other));

    ptr_c_strcpy_static(&other, "replaced data");
    printf("other data: %s\n", ptr_c_str(&other));

    ptr_c_strcpy_static(&other_larger, "replaced data");
    printf("other_larger data: %s\n", ptr_c_str(&other_larger));

    for (size_t i = 0; i < 10; i++) {
        ptr_c_strcat_static(&other_larger, ", more data!");
        ptr_c_strcat_static(&other_much_larger, ", more data!");
        printf("other_larger data: %s (%zd)\n", ptr_c_str(&other_larger), c_strlen(other_larger));
        printf("other_much_larger data: %s (%zd)\n", ptr_c_str(&other_much_larger), ptr_c_strlen(&other_much_larger));
    }

    for (size_t i = 0; i < 10; i++) {
        ptr_c_strcat(&other_much_larger, &other_larger);
        printf("other_much_larger data: %s (%zd)\n", ptr_c_str(&other_much_larger), ptr_c_strlen(&other_much_larger));

        c_strcat(other_much_larger, other_larger);
        printf("other_much_larger data: %s (%zd)\n", ptr_c_str(&other_much_larger), ptr_c_strlen(&other_much_larger));
    }
    
    return 0;
}
