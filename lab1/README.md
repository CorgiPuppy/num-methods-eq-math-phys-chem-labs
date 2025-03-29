# Лабораторная работа 1
## Вариант 22

<table style="width:100%">
    <tr>
        <th style="text-align:center; vertical-align:middle">Вариант</th>
        <th style="text-align:center; vertical-align:middle">Уравнение</th>
        <th style="text-align:center; vertical-align:middle">Интервалы переменных</th>
        <th style="text-align:center; vertical-align:middle">Начальные и граничные условия</th>
    </tr>
    <tr>
        <td style="text-align:center; vertical-align:middle">22</td>
        <td style="text-align:center; vertical-align:middle">$$\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial t^2}$$</td>
		<td style="text-align:center; vertical-align:middle">$$x \in [0, 1]$$ <br> $$t \in [0, 1]$$</td>
		<td style="text-align:center; vertical-align:middle">$$u(t = 0, x) = e^x$$ <br> $$u(t, x = 0) = e^t$$ <br> $$u(t, x = 1) = e^{t+1}$$</td>
    </tr>
</table>

Для заданного уравнения:
1. записать явную разностную схему;
2. определить порядок аппроксимации разностной схемы;
3. получить условие устойчивости разностной схемы на шаг (с помощью метода гармоник);
4. вывести рекуррентное соотношение;
5. составить алгоритм (блок-схему) расчёта;
6. построить программу на любом удобном языке программирования;
7. провести численный расчёт с использованием различных значений $$\Delta t (0.1, 0.01, 0.001), h = 0.1$$;
8. составить отчёт о проделанной работе.
