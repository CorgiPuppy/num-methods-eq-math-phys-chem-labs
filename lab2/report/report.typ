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

		table.cell(text(size: 14.4pt, "Выполнил студент группы КС-36:"), align: right), table.cell(text(size: 14.4pt, "Золотухин Андрей Александрович"), align: left),
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

#set text(font: "Comic Neue", weight: 600) // testing: omit

#diagram(
	node-stroke: 1pt,
	node((0,0), [Start], corner-radius: 2pt, extrude: (0, 3)),
	edge("-|>"),
	node((0,1), align(center)[
		Hey, wait,\ this flowchart\ is a trap!
	], shape: diamond),
	edge("d,r,u,l", "-|>", [Yes], label-pos: 0.1)
)
