#define STBI_ONLY_BMP // собщает библиотеке `stb_image`что использовать только ее поддержку формата BMP.
#define STB_IMAGE_IMPLEMENTATION //определяет реализацию библиотеки stb_image
#include "../stb/stb_image.h" //включает заголовочный файл stb_image.h, который содержит определения функций для загрузки и обработки изображений. Путь `"../stb/stb_image.h"` указывает, где находится файл

#define STB_IMAGE_WRITE_IMPLEMENTATION //определяет реализацию stb_image_write, библиотеки для записи изображений.
#include "../stb/stb_image_write.h" //функции для записи изображений в различные форматы.

#include <time.h> //для работы с функциями времени.используются для измерения скорости выполнения кода

extern void to_grayscale_red(char *buffer, int width, int height, int channels); //объявляет функцию.Функция принимает указатель на буфер изображения, ширину, высоту и количество каналов изображения. 

int main(int argc, char *argv[]) { //очка входа в программу.argc - количество аргументов командной строки, а argv - массив указателей на строковые аргументы.

    int width, height, channels; 
    unsigned char *img; //Unsigned char символьный тип данных, в котором переменная занимает все 8 бит памяти и отсутствует знаковый бит (diapozon tipov dannih0-255) (для хранения данных изображения
    int res = 0; //hranenie koda zavethenia programi

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    img = stbi_load(argv[1], &width, &height, &channels, 0); //Загр изобр из файла, указанного в первом арг командной строки. Функция stbi_load возвращает указатель на данные изображения, а также записывает в переданные по адресу переменные width,height, channels соответствующие значения.  
    if (img == NULL) { //проверка успешной загрузки изображения
        printf("Error while reading from file %s\n", argv[1]);
        return 2;
    }

    clock_t begin = clock(); // запоминает текущее время чтоб измерить вр выполн
    to_grayscale_red(img, width, height, channels);
    clock_t end = clock();
    printf("%lf\n", (double)(end - begin) / CLOCKS_PER_SEC); //Выводит время выполнения преобразования в сек


    if (!stbi_write_bmp(argv[2], width, height, channels, img)) { //Сохр новое изобр в файл, указанный во 2 арг ком строки. Функция `stbi_write_bmp` возвращает 0, если запись не удалась.

        printf("Error while writing to file %s", argv[2]);
        res = 3; //код заверш
    }

    stbi_image_free(img); //строка освобождает память,img - это указатель на инф об изобр, загр с помощью функц stbi_load
    return res; //возвращает значение res
}