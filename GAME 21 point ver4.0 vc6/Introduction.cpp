#include <stdio.h>

void intro()
{
	printf("游戏说明:\n\n"
				"数字的值：A=1  2~10为本身  J、Q、K值全为10\n\n"
				"输赢规则：最接近21但不超过21者为赢\n\n"
				"流程:\n1、发牌：玩家先开始，双方各发两张牌，但都只亮第一张牌，第二张牌为“暗牌”。\n"
				"2、要牌：玩家先开始选择是否再要一张牌\n"
				"3、计算双方牌点数之和，比较大小。\n"
				"\n"
				"补充：一方先达到21点则无视对方点数取胜。\n"
				"发牌时取得A与10或J Q K,则称为取得BlackJack\n"
				"一方超出21视为“爆牌”，若对方不爆牌则对方胜\n\n");
}