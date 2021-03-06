МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 3<br/> по дисциплине "Программирование"

<br/>

студента 1 курса группы 191(2)  
Михерский Михаил Ростиславович
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>

<br/><br/>

Симферополь, 2019

# Лабораторная работа №3 Дешифровка текста из изображения

**Цель:**

1. Закрепить навыки разработки программ использующих операторы цикла;
2. Закрепить навыки разработки программ использующих массивы;
3. Освоить методы подключения сторонних библиотек.

### Ход работы

![](https://raw.githubusercontent.com/M-850/Task.1_1/master/Lab_3/pic7.bmp "Рис.1 Изображение для расшифровки")

Рис.1 Изображение для расшифровки

**Ключ** - 00r 00b 00g 01r 01b 01g 10r 10b

**Код программы**

```c++
#include <iostream>
#include"libbmp.h"
void Out_putting(int &counter, unsigned char &result)
{	
		counter = 0;
		char zeroing = 0x0;
		result >>= 1;
		if (result == 0x00)
		{
			std::cout << std::endl;
			exit(1);
		}
		std::cout << result;
		result &= zeroing;
}
void Text_(unsigned char &result, int &counter, size_t x, size_t y, BmpImg &img)
{
	unsigned char mask = 0x01;
	if ((mask & img.red_at(x, y)) != 0)
	{
		result |= mask;
	}
	result <<= 1;
	counter++;
	if (counter == 8) 
	{
		Out_putting(counter, result);
	}
	if ((mask & img.blue_at(x, y)) != 0)
	{
		result |= mask;  
	}
	result <<= 1;
	counter++;
	if (counter == 8)
	{
		Out_putting(counter, result);
	}
	if ((mask & img.green_at(x, y)) != 0)
	{
		result |= mask;  
	}
	result <<= 1;
	counter++;
	if (counter == 8)
	{
		Out_putting(counter, result);
	}
}
int main()
{
	BmpImg img;
	img.read("pic7.bmp");
	const int width = img.get_width();
	const int height = img.get_height();
	unsigned char result = 0x00;
	int counter = 0;
	size_t x = 0, y = 0;
	for (x = 0;  x < width; x++)
	{
		for (y = 0; y < height; y++)
		{
			Text_(result, counter, x, y, img);
		}
	}	
}
```

**Декодированное сообщение представлено ниже:** 

Andrew Jackson (March 15, 1767 ▬ June 8, 1845) was an American soldier and statesman who served as the seventh president of the United States from 1829 to 1837. Before being elected to the presidency, Jackson gained fame as a general in the United States Army and served in both houses of the U.S. Co
ngress. As president, Jackson sought to advance the rights of the "common man"[1] against a "corrupt aristocracy"[2] and to preserve the Union.
Born in the colonial Carolinas to a Scotch-Irish family in the decade before the American Revolutionary War, Jackson became a frontier lawyer and married Rachel Donelson Robards. He served briefly in the United States House of Representatives and the United States Senate, representing Tennessee. Aft
er resigning, he served as a justice on the Tennessee Supreme Court from 1798 until 1804. Jackson purchased a property later known as The Hermitage, and became a wealthy, slaveowning planter. In 1801, he was appointed colonel of the Tennessee militia and was elected its commander the following year.
 He led troops during the Creek War of 1813▬1814, winning the Battle of Horseshoe Bend. The subsequent Treaty of Fort Jackson required the Creek surrender of vast lands in present-day Alabama and Georgia. In the concurrent war against the British, Jackson's victory in 1815 at the Battle of New Orlea
ns made him a national hero. Jackson then led U.S. forces in the First Seminole War, which led to the annexation of Florida from Spain. Jackson briefly served as Florida's first territorial governor before returning to the Senate. He ran for president in 1824, winning a plurality of the popular and
electoral vote. As no candidate won an electoral majority, the House of Representatives elected John Quincy Adams in a contingent election. In reaction to the alleged "corrupt bargain" between Adams and Henry Clay and the ambitious agenda of President Adams, Jackson's supporters founded the Democrat
ic Party.
Jackson ran again in 1828, defeating Adams in a landslide. Jackson faced the threat of secession by South Carolina over what opponents called the "Tariff of Abominations." The crisis was defused when the tariff was amended, and Jackson threatened the use of military force if South Carolina attempted
 to secede. In Congress, Henry Clay led the effort to reauthorize the Second Bank of the United States. Jackson, regarding the Bank as a corrupt institution, vetoed the renewal of its charter. After a lengthy struggle, Jackson and his allies thoroughly dismantled the Bank. In 1835, Jackson became th
e only president to completely pay off the national debt, fulfilling a longtime goal. His presidency marked the beginning of the ascendancy of the party "spoils system" in American politics. In 1830, Jackson signed the Indian Removal Act, which forcibly relocated most members of the Native American
tribes in the South to Indian Territory. The relocation process dispossessed the Indians and resulted in widespread death and disease. Jackson opposed the abolitionist movement, which grew stronger in his second term. In foreign affairs, Jackson's administration concluded a "most favored nation" tre
aty with Great Britain, settled claims of damages against France from the Napoleonic Wars, and recognized the Republic of Texas. In January 1835, he survived the first assassination attempt on a sitting president.
In his retirement, Jackson remained active in Democratic Party politics, supporting the presidencies of Martin Van Buren and James K. Polk. Though fearful of its effects on the slavery debate, Jackson advocated the annexation of Texas, which was accomplished shortly before his death. Jackson has bee
n widely revered in the United States as an advocate for democracy and the common man. Many of his actions proved divisive, garnering both fervent support and strong opposition from many in the country. His reputation has suffered since the 1970s, largely due to his role in Native American removal.
Surveys of historians and scholars have ranked Jackson favorably among U.S. presidents.

**Вывод:** написал программу на языку С++ которая по заданному ключу восстанавливает зашифрованный текст из изображения. Научился работать с побитовыми операторами,  освоил методы подключения сторонних библиотек, закрепил навык создания программ использующие операторы цикла.