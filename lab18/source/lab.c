#include <stdio.h>//standartni zagolovochniy file (funkcie vvoda vivoda (printf))

void to_grayscale_red_3(char *buffer, int width, int height, int channels) {
    int index = 0;
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            // Получаем значение красного канала
            int red = buffer[index];

            // Записываем значение красного канала в остальные каналы
            buffer[index + 1] = red;
            buffer[index + 2] = red;

            index += channels;
        }
    }
}

void to_grayscale_red_4(char *buffer, int width, int height, int channels) {
    int index = 0;
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            // Получаем значение красного канала
            int red = buffer[index];

            // Записываем значение красного канала в остальные каналы
            buffer[index + 1] = red;
            buffer[index + 2] = red;
            buffer[index + 3] = red;

            index += channels;
        }
    }
}

void to_grayscale_red(char *buffer, int width, int height, int channels) {
    if (channels == 3) {
        to_grayscale_red_3(buffer, width, height, channels);
    } else if (channels == 4) {
        to_grayscale_red_4(buffer, width, height, channels);
    } else {
        // Вывод ошибки: неправильное количество каналов
        printf("Error: Invalid number of channels.\n");
    }
}