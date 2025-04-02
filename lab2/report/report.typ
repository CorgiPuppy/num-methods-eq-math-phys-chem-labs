#import "@preview/diverential:0.2.0": *
#import "@preview/polytonoi:0.1.0": *
#import "@preview/fletcher:0.5.7" as fletcher: diagram, node, edge
#import fletcher.shapes: diamond

#show raw.where(block: true): it => { set par(justify: false); grid(
  columns: (100%, 100%),
  column-gutter: -100%,
  block(width: 100%, inset: 1em, for i in it.text.split("\n") {
    linebreak()
  }),
  block(radius: 1em, fill: luma(246), width: 100%, inset: 1em, it),
)}
#show table.cell.where(y: 0): strong

#set page(
	paper: "a4",
	margin: (x: 0.8cm, y: 1.5cm),
)

#set text(
	font: "New Computer Modern",
	size: 11pt,
)

#set par(
	first-line-indent: 2em,
)

#set page(numbering: none)
#align(center, block[
	#set text(size: 12pt)
	#set heading(outlined: false)
	= Министерство науки и вышего образования Российской Федерации
	= Федеральное государственное бюджетное образовательное учреждение высшего образования
	#set text(lang: "fr")
	= "Российский химико-технологический университет имени Д.И. Менделеева" 
])

#let count = 0
#while count < 10 {
	$ #linebreak() $
	count = count + 1
}

#align(center, block[
	#set text(size: 16pt)
	#set heading(outlined: false)
	= ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №2
	= Вариант 22
])

#let count = 0
#while count < 10 {
	$ #linebreak() $
	count = count + 1
}

#align(center)[
	#table(
		columns: (8.85cm,) + (10.8cm,),
		stroke: none,

		table.cell(text(size: 13.4pt, "Выполнил студент группы КС-36:"), align: right), table.cell(text(size: 14.4pt, "Золотухин Андрей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Ссылка на репозиторий:"), align: right), table.cell(text(size: 14.4pt, "https://github.com/"), align: left),
		table.cell("", align: right), table.cell(text(size: 14.4pt, "CorgiPuppy/"), align: left),
		table.cell("", align: right), table.cell(text(size: 14.4pt, "num-methods-eq-math-phys-chem-labs"), align: left),
		table.cell(text(size: 14.4pt, "Принял:"), align: right), table.cell(text(size: 14.4pt, "Лебедев Данила Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Дата сдачи:"), align: right), table.cell(text(size: 14.4pt, "02.04.25"), align: left),
		
	)
]

#let count = 0
#while count < 5 {
	$ #linebreak() $
	count = count + 1
}

#align(center, block[
	#set text(size: 14.4pt)
	#set heading(outlined: false)
	= Москва
	= 2025
])

#pagebreak()

#align(center, block[
	#outline(		
		title: "Оглавление",
	)
])

#pagebreak()

#align(center, block[
	= Описание задачи
])
#set text(size: 12pt)
#table(
	columns: (auto, auto, auto, auto),
	align: center + horizon,
	table.header[Вариант][Уравнение][Интервалы переменных][Начальные и граничные условия],
	[22], [$dvp(u, t) = dvp(u, x, deg: 2)$], [x in [0, 1] \ t in [0, 1]], [$u(t = 0, x) = e^x$ \ $u(t, x = 0) = e^t$ \ $u(t, x = 1) = e^(t+1)$],
)
Для заданного уравнения:
+ записать неявную разностную схему;
+ определить порядок аппроксимации разностной схемы;
+ доказать абсолютную устойчивость разностной схемы (с помощью метода гармоник);
+ привести схему к виду, удобному для использования метода прогонки;
+ проверить сходимость прогонки;
+ найти $α_1$, $#ptgk("b")_1$, $u_N^(n+1)$
+ записать рекуррентное прогоночное соотношение;
+ составить алгоритм (блок-схему) расчёта;
+ построить программу на любом удобном языке программирования;
+ провести численный расчёт с использованием различных значений #emph([#ptgk("D")t(0.1, 0.01, 0.001)]), #emph([h = 0.1]);
+ составить отчёт о проделанной работе;
+ сравнить результаты расчётов заданий №1 и №2 друг с другом, а также с истинными значениями функции #emph([u]) и в соответствующих точках разностной сетки (#emph([истинное решение уравнения будет выдано преподавателем после выполнения расчётов по явной и неявной разностным схемам)]).

#pagebreak()

#align(center, block[
	= Выполнение задачи
	== Задание 1
]) \

Записать неявную разностную схему: 
#set math.equation(numbering: "(1)")
$ frac(u_j^(n+1)-u_j^n, #ptgk("D")t) = frac(u_(j+1)^(n+1)-2u_j^(n+1)+u_(j-1)^(n+1), h^2). $ <implicit> \

В записанной разностной схеме @implicit аппроксимация второй производной функции #emph([u(t, x)]) по координате рассматривается на #emph([n+1])-м шаге по времени, т.е. относительно точки $t^(n+1)$, для которой рассматривается аппроксимация всего уравнения. Такая разностная схема называется *неявной*.

#align(center, block[
	== Задание 2
]) 
Определить порядок аппроксимации разностной схемы @implicit:
Для этого запишу разложение значений $u_j^(n+1)$, $u_(j+1)^(n+1)$, $u_j^(n+1)$, $u_(j-1)^(n+1)$ в ряд Тейлора относительно точки

#align(center, block[
	== Задание 3
])
Доказать абсолютную устойчивость разностной схемы @implicit (с помощью метода гармоник):
Представляю решение разностной схемы в виде гармоники:
$ u_j^n = #ptgk("l")^n e^(i α j). $ <harmonic>
Подставляя @harmonic в разностную схему @implicit, получаю:
$ frac(#ptgk("l")^(n+1) e^(i α j)-#ptgk("l")^n e^(i α j), #ptgk("D") t) = frac(#ptgk("l")^(n+1) e^(i α (j+1))-2#ptgk("l")^(n+1) e^(i α j)+#ptgk("l")^(n+1) e^(i α (j-1)), h^2). $
Упрощаю полученное выражение, деля левую и правую его части на $#ptgk("l")^n e^(i α j)$
Преобразую комплексные числа из экспоненциальной формы в тригонометрическую:
$ e^(plus.minus i α) => cos α plus.minus sin α => frac(#ptgk("l")-1, #ptgk("D")) = frac(2 cos α-2, h^2). $
Используя тригонометрические тождества
$ cos α = cos^2 frac(α, 2) - sin^2 frac(α, 2) = 1 - 2 sin^2 frac(α, 2), $

#diagram(
	node-stroke: 1pt,
	node((0,0), [Start], corner-radius: 2pt, extrude: (0, 3)),
	edge("-|>"),
	node((0,1), align(center)[
		Hey, wait,\ this flowchart\ is a trap!
	], shape: diamond),
	edge("d,r,u,l", "-|>", [Yes], label-pos: 0.1)
)
