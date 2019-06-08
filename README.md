# visio2state
Назначение: создание программного кода на языке СИ.  
Исходные данные: графическое представление программного автомата в Microsoft Visio.
Среда проектирования: страница документа  Microsoft Visio.
Способ трансляции: вызов макроса.
Обязательное требование: разрешение работы макросов Microsoft Visio. 

Документы проекта включают два файла:  auto.vss  (фигуры) и auto.vsdm (документ Visio с поддержкой макросов).
Документы  auto.vss  и auto.vsdm необходимо разместить в любой папке вашего проекта. 
После запуска «трансляции» (вызова макроса) в этой же папке появляются файлы fsa.c (код автоматов) и fsa.h *описание функций).

В примере  auto.vsdm выполнена предварительная настройка, в том числе:
На листе A0 проекта размещается фигура SW_Auto. Наличие этой фигуры на листе A0 объявляет содержимое листа автоматом. На листе A1 находится пример еще одного автомата. Обязателен ввод в поле  SW_Auto только имени автомата (в примере aSystem), так как в среде СИ будет создана переменная с тем же именем.  Не используйте  опасные имена, возможны ошибки компиляции.
Автомат примера A0 представляет собой функцию void fsa_aSystem(void); //Первый автомат
Запуск автомата обычно размещают в бесконечном цикле функции main, например:
while(1) {  
fsa_aSystem(); //Первый автомат
fsa_aSys(); //Второй автомат  }

На листе A0 проекта размещена фигура SW_Error. Результаты трансляции (в том числе ошибки) выводятся в тексте фигуры.
На листе A0 проекта размещена фигура SW_Header. Содержимое текста фигуры копируется в файл fsa.h   - рекомендуется отключить автоввод заглавной буквы в настройках Visio что бы не создавать синтаксических ошибок (  Void F1(void);   вместо void F1(void);  ).
Кнопка «Пуск транслятора» связана с макросом. Запускать макрос можно и вручную.

Создание автомата.
Пример автомата содержит три вершины (состояния) SW_State, связанные дугами переходов.
Каждая вершина (SW_State) имеет уникальный номер, автоматически добавляемый при вставке фигуры. Внимание! При создании новой страницы документа Visio нужно вручную активировать автонумерацию с настройками по образцу.
В верхнюю ячейку SW_State вводится имя вершины.  Используется для комментариев, требования к оформлению отсутствуют.
Вторая сверху ячейка – действия, выполняемые при входе в вершину, однократно.  Допустимы любые СИ конструкции.
Третья сверху ячейка – действия, выполняемые при нахождении в данном состоянии, многократно, при каждом запуске функции автомата void fsa_aSystem(void); //Первый автомат.  Допустимы любые СИ конструкции.
Четвертая сверху ячейка – действия, выполняемые при выходе из состояния, однократно.  Допустимы любые СИ конструкции.
Фигура SW_State автоматически изменяет размер при расширении соответствующих тестовых полей.

Для соединения вершин используют дуги SW_conn. Визуальная толщина  линии дуги  соответствует приоритету – соединения при помощи SW_connHi обладают наивысшим приоритетом, SW_connLo – низшим. Линии одинаковой толщины, созданные ранее имеют более высокий приоритет по сравнению с более поздними по времени создания, но таких дуг лучше не создавать. Фактически приоритет означает порядок размещения переходов в результирующей цепочке команд:
if () else if () else… 
Необходимость использования приоритетов демонстрируется в примере при переходе из состояния 2 в состояние 3.  При одновременном срабатывании условий uX2 uX3 uX4 поведение системы было бы непредсказуемо, стандартно разработчику приходится усложнять условие перехода (например для первой дуги это  uX2 * !uX3 * !uX4 ).

Каждая дуга имеет передвигаемый блок условия/действия.
В числителе дроби записано условие перехода, допустимы конструкции языка СИ, с учетом того что блок будет размещен внутри оператора if. Например, условие uX1 приведет к появлению перехода
if (uX1) 
В знаменателе допустимы любые СИ конструкции, они будут размещены в теле оператора if.

Кодировка результирующих файлов: я использую utf-8.
Если по какой-то причине вас utf-8 не устраивает, есть три пути решения:
1.	Поменять в макросе     Set fileStream = fso.CreateTextFile(filePath, True, True)
на     Set fileStream = fso.CreateTextFile(filePath, True, False)
2.	Воспользоваться Notepad ++
3.	Писать автору (мне, то есть) пусть добавит переключатель кодировки.


