#include <stdio.h>
#include <stdlib.h>

// Самый простой split для начинающих
// Не обрабатывает все случаи, но показывает идею
char** simple_split(const char* str) {
    // Сначала посчитаем слова
    int count = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        // Находим начало слова (не пробел после пробела)
        if (str[i] != ' ' && (i == 0 || str[i-1] == ' ')) {
            count++;
        }
        i++;
    }
    
    // Выделяем память
    char** result = (char**)malloc((count + 1) * sizeof(char*));
    
    // Разбиваем на слова
    int word_num = 0;
    int start = 0;
    int len = 0;
    
    for (i = 0; ; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (len > 0) {  // было слово
                // Выделяем память для слова
                result[word_num] = (char*)malloc((len + 1) * sizeof(char));
                
                // Копируем слово
                for (int j = 0; j < len; j++) {
                    result[word_num][j] = str[start + j];
                }
                result[word_num][len] = '\0';
                
                word_num++;
            }
            
            start = i + 1;
            len = 0;
            
            if (str[i] == '\0') break;
        } else {
            len++;
        }
    }
    
    result[word_num] = NULL;  // конец массива
    return result;
}

int main() {
    char** words = simple_split("hello world");
    
    printf("Слова:\n");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%d: %s\n", i, words[i]);
        free(words[i]);  // освобождаем каждое слово
    }
    
    free(words);  // освобождаем массив
    return 0;
}
