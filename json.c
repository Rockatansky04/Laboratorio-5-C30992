#include <stdio.h>
#include <cjson/cJSON.h>

int Json() {

    FILE *test_fp = fopen("data.json", "r");
    if (test_fp != NULL) {
        printf("El archivo data.json ya existe. Se sobrescribirá.\n");
        fclose(test_fp);
    }

    cJSON *json = cJSON_CreateObject();
    if (json == NULL) {
        printf("Error al crear objeto JSON.\n");
        return 1;
    }

    cJSON_AddStringToObject(json, "Nombre", "Daniel Barrantes");
    cJSON_AddNumberToObject(json, "edad", 20);
    cJSON_AddStringToObject(json, "Carnet", "C30992");
    cJSON_AddStringToObject(json, "Estudiante activo", "True");

 
    char *json_str = cJSON_Print(json);
    FILE *fp = fopen("data.json", "w");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        cJSON_Delete(json);
        cJSON_free(json_str);
        return 1;
    }
    
    fputs(json_str, fp);
    fclose(fp);

    cJSON_free(json_str);
    cJSON_Delete(json);

    return 0;
}
