#include<stdio.h>
#include<json-c/json.h>

void num_add(int x, int y){
    int z = x+y;
    printf("%d\n",z);
}


int main(int argc, char **argv){

    FILE *fp;
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *values;
    struct json_object *num_values;
    {
        /* data */
    };
    
    size_t n_values;
    size_t i;
    struct json_object *num1;
    struct json_object *num2; 


    fp = fopen("test.json","r");
    fread(buffer,1024,1,fp);
    fclose(fp);
    
    parsed_json = json_tokener_parse(buffer);
    
    json_object_object_get_ex(parsed_json,"values",&values);
    
    n_values = json_object_array_length(values);

    printf("length of values is : %lu\n",n_values);

    for(i=0;i<n_values;i++){
        num_values = json_object_array_get_idx(values, i);
        json_object_object_get_ex(num_values,"num1",&num1);
        json_object_object_get_ex(num_values,"num2",&num2);
        printf("%d", json_object_get_int(num1));
        printf(" + %d = ", json_object_get_int(num2));
        num_add(json_object_get_int(num1),json_object_get_int(num2));
    }

}