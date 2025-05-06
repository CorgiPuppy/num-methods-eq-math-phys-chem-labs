# Лабораторная работа 1
## Вариант 9

<table style="width:100%">
    <tr>
        <th style="text-align:center; vertical-align:middle">Вариант</th>
        <th style="text-align:center; vertical-align:middle">Уравнение</th>
        <th style="text-align:center; vertical-align:middle">Метод</th>
        <th style="text-align:center; vertical-align:middle">Граничные условия</th>
    </tr>
    <tr>
        <td style="text-align:center; vertical-align:middle">9</td>
        <td style="text-align:center; vertical-align:middle">$$\frac{du}{dx} = \frac{d^{2}u}{dx^{2}} + 4$$</td>
		<td style="text-align:center; vertical-align:middle">Установление со <br> схемой Кранка- <br> Николсона</td>
		<td style="text-align:center; vertical-align:middle">$$\begin{cases} u(t, x = 0) = 1 \\ u(t, x = 1) = 6,7 \end{cases}$$</td>
    </tr>
</table>

Для заданного уравнения:
1. Представить задачу в нестационарном виде;
2. Записать разностную схему в соответствии с методом варианта;
3. Для метода установления, требующего прогонки, привести схему к виду, удобному для использования метода прогонки, проверить сходимость прогонки, вывести $$\alpha_1$$, $$\beta_1$$, $$u_N^{n+1}$$ из граничных условий;
4. Записать рекуррентное соотношение;
5. Составить алгоритм (блок-схему) расчёта;
6. Построить программу на любом удобном языке программирования;
7. Для метода установления с использованием явной схемы провести расчёты при <em>h = {0.1; 0.01}</em> и трёх различных $$\Delta t$$ (подобрать их самим), где $$\Delta t \le \frac{h^{2}}{\nu h + 2\sigma}$$;
8. Для метода установления с использованием неявных схем проводить расчёты при <em>h = {0.1; 0.01}</em> и $$\Delta t$$<em> = {0.1; 0.01; 0.001}</em>;
9. Сравнить результаты вычислений между собой в точках: <em>x = {0;</em> <em>0.1;</em> <em>0.2;</em> <em>0.3;</em> <em>0.4;</em> <em>0.5;</em> <em>0.6;</em> <em>0.7;</em> <em>0.8;</em> <em>0.9;</em> <em>1}</em>.
