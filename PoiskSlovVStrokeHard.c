/* 
    ПРОГРАММА: Разделение строки на слова (split)
    Задача: Разбить строку на слова по пробелам
*/

#include <stdio.h>   // для printf
#include <stdlib.h>  // для malloc и free

// Функция проверяет, пробел ли это
// Возвращает 1 если пробел, 0 если нет
int is_space(char c) {
    // Сравниваем символ с тремя видами пробелов
    if (c == ' ') return 1;      // обычный пробел
    if (c == '\t') return 1;     // табуляция
    if (c == '\n') return 1;     // новая строка
    return 0;                    // не пробел
}

/*
    ФУНКЦИЯ: split - разбивает строку на слова
    Вход: str - строка для разбиения (например, "привет мир")
    Выход: массив строк (слов) или NULL если ошибка
    
    ПРИМЕР:
      split("привет мир") вернёт ["привет", "мир", NULL]
      split("  а  б  ")    вернёт ["а", "б", NULL]
*/
char** split(const char* str) {
    // ШАГ 1: Проверяем, не пустая ли строка
    if (str == NULL) {  // если нам передали NULL
        printf("Ошибка: передан NULL указатель!\n");
        return NULL;
    }
    
    // Если строка пустая (первый символ '\0')
    if (str[0] == '\0') {
        // Создаём массив из одного элемента - NULL
        char** result = (char**)malloc(sizeof(char*));
        if (result != NULL) {
            result[0] = NULL;  // единственный элемент = NULL
        }
        return result;
    }
    
    // ШАГ 2: Считаем, сколько слов в строке
    int word_count = 0;    // счётчик слов
    int inside_word = 0;   // 0 = вне слова, 1 = внутри слова
    
    // Проходим по всем символам строки
    int i = 0;
    while (str[i] != '\0') {  // пока не конец строки
        if (is_space(str[i]) == 0) {  // если НЕ пробел
            if (inside_word == 0) {   // и мы вне слова
                word_count++;         // нашли новое слово!
                inside_word = 1;      // теперь мы внутри слова
            }
        } else {  // если пробел
            inside_word = 0;  // выходим из слова (или остаёмся вне)
        }
        i++;  // переходим к следующему символу
    }
    
    printf("Нашёл %d слов в строке\n", word_count);
    
    // ШАГ 3: Выделяем память для массива указателей
    // Нужно: word_count указателей + 1 для NULL в конце
    char** result = (char**)malloc((word_count + 1) * sizeof(char*));
    
    // Проверяем, выделилась ли память
    if (result == NULL) {
        printf("Не хватило памяти для массива!\n");
        return NULL;
    }
    
    // Обнуляем все указатели в массиве
    for (int j = 0; j <= word_count; j++) {
        result[j] = NULL;
    }
    
    // Если слов нет, возвращаем массив с NULL
    if (word_count == 0) {
        result[0] = NULL;
        return result;
    }
    
    // ШАГ 4: Копируем слова в память
    int current_word = 0;    // индекс текущего слова (0, 1, 2...)
    int word_start = -1;     // позиция начала слова в строке
    int word_len = 0;        // длина текущего слова
    
    i = 0;  // снова начинаем с начала строки
    while (str[i] != '\0') {
        if (is_space(str[i]) == 0) {  // если НЕ пробел
            if (word_start == -1) {   // если слово ещё не начато
                word_start = i;       // запоминаем начало слова
            }
            word_len++;               // увеличиваем длину слова
        } else {  // если пробел
            if (word_start != -1) {   // если слово было начато
                // Выделяем память для слова
                // +1 для символа '\0' в конце
                result[current_word] = (char*)malloc((word_len + 1) * sizeof(char));
                
                // Проверяем, выделилась ли память
                if (result[current_word] == NULL) {
                    printf("Не хватило памяти для слова %d!\n", current_word);
                    // Освобождаем всё, что уже выделили
                    for (int k = 0; k < current_word; k++) {
                        free(result[k]);
                    }
                    free(result);
                    return NULL;
                }
                
                // Копируем слово из строки в выделенную память
                for (int k = 0; k < word_len; k++) {
                    result[current_word][k] = str[word_start + k];
                }
                // Добавляем '\0' в конец слова
                result[current_word][word_len] = '\0';
                
                current_word++;  // переходим к следующему слову
                word_start = -1; // сбрасываем начало слова
                word_len = 0;    // сбрасываем длину
            }
        }
        i++;  // следующий символ
    }
    
    // ШАГ 5: Обрабатываем последнее слово (если строка не кончается пробелом)
    if (word_start != -1) {
        result[current_word] = (char*)malloc((word_len + 1) * sizeof(char));
        
        if (result[current_word] == NULL) {
            printf("Не хватило памяти для последнего слова!\n");
            for (int k = 0; k < current_word; k++) {
                free(result[k]);
            }
            free(result);
            return NULL;
        }
        
        // Копируем последнее слово
        for (int k = 0; k < word_len; k++) {
            result[current_word][k] = str[word_start + k];
        }
        result[current_word][word_len] = '\0';
        current_word++;  // увеличиваем счётчик слов
    }
    
    // ШАГ 6: Добавляем NULL в конец массива
    result[current_word] = NULL;
    
    return result;  // возвращаем результат
}

/*
    ФУНКЦИЯ: free_split - освобождает память
    Вход: words - массив строк, который вернула split
    Задача: освободить ВСЮ память, выделенную в split
*/
void free_split(char** words) {
    // Проверяем, не NULL ли нам передали
    if (words == NULL) {
        return;  // нечего освобождать
    }
    
    // Проходим по всем словам
    int i = 0;
    while (words[i] != NULL) {  // пока не встретим NULL
        free(words[i]);  // освобождаем память слова
        i++;
    }
    
    // Освобождаем сам массив указателей
    free(words);
}

/*
    ФУНКЦИЯ: print_words - печатает массив слов
    Вход: words - массив строк
    Просто печатает все слова с их номерами
*/
void print_words(char** words) {
    if (words == NULL) {
        printf("Массив слов = NULL\n");
        return;
    }
    
    printf("Массив слов:\n");
    int i = 0;
    while (words[i] != NULL) {
        printf("  [%d] = '%s'\n", i, words[i]);
        i++;
    }
    if (i == 0) {
        printf("  (пусто)\n");
    }
    printf("Конец массива (words[%d] = NULL)\n", i);
}

/*
    ГЛАВНАЯ ФУНКЦИЯ: тестируем split
*/
int main() {
    printf("=== ТЕСТ 1: Обычная строка ===\n");
    char** words1 = split("привет мир как дела");
    print_words(words1);
    free_split(words1);
    printf("\n");
    
    printf("=== ТЕСТ 2: Много пробелов ===\n");
    char** words2 = split("  я   учу   C  ");
    print_words(words2);
    free_split(words2);
    printf("\n");
    
    printf("=== ТЕСТ 3: Одно слово ===\n");
    char** words3 = split("школа21");
    print_words(words3);
    free_split(words3);
    printf("\n");
    
    printf("=== ТЕСТ 4: Пустая строка ===\n");
    char** words4 = split("");
    print_words(words4);
    free_split(words4);
    printf("\n");
    
    printf("=== ТЕСТ 5: Только пробелы ===\n");
    char** words5 = split("   \t  \n ");
    print_words(words5);
    free_split(words5);
    printf("\n");
    
    printf("=== ТЕСТ 6: С табуляцией и переводом строки ===\n");
    char** words6 = split("раз\tдва\nтри");
    print_words(words6);
    free_split(words6);
    printf("\n");
    
    printf("=== ТЕСТ 7: Длинная строка ===\n");
    char** words7 = split("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    print_words(words7);
    free_split(words7);
    
    return 0;
}
