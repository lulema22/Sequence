cmake_minimum_required(VERSION 3.10)
# Или более новая версия, если нужно (например, 3.20 или 3.30)
project(tmp_pohyi)

# Устанавливаем стандарт языка
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Список исходных файлов (добавьте .cpp при необходимости)
set(SOURCE_FILES
        main_1.cpp
        ArraySequenceNew.h
        DynamicArrayNew.h
        ListSequenceNew.h
        SequenceNew.h
        ArraySequenceNew.h
        DynamicArrayNew.h
        ListSequenceNew.h
        SequenceNew.h
        Person.h
        ZipUnzip.h
        Deck.h
        tmp_1.cpp
        main_2.cpp
        MutableImmutableDek.h
)

# Создаём исполняемый файл
add_executable(tmp_pohyi ${SOURCE_FILES})

#ad_definitions(-DLOCAL)

# При необходимости подключите дополнительные библиотеки или пути к заголовкам:
# target_include_directories(tmp_pohyi PRIVATE ${PROJECT_SOURCE_DIR}/some_include_dir)
# target_link_libraries(tmp_pohyi PRIVATE some_lib)
