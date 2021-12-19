//<---Lipsar корабли по квесту Предложение Пирата
void CreatePGG_War(ref ch, int iNation, ref shipOwner)
{
	aref rShip;
	ref rMerch;
	int iType, cl, cl1, i, j;
	ref refShip;
	refShip = GetRealShip(sti(shipOwner.ship.Type));
	int storeArray1[SHIP_TYPES_QUANTITY];
	j = 0;
	switch(sti(refShip.Class))
	{
		case 7:
			cl = 3;
			cl1 = 15;
		break;
		case 6:
			cl = 3;
			cl1 = 15;
		break;
		case 5:
			cl = 15;
			cl1 = 28;
		break;
		case 4:
			cl = 28;
			cl1 = 52;
		break;
		case 3:
			if (MOD_SKILL_ENEMY_RATE == 10)
			{
				cl = 52;
				cl1 = 84;
			}
			else
			{
				cl = 28;
				cl1 = 52;
			}
		break;
		case 2:
			if (MOD_SKILL_ENEMY_RATE == 10)
			{
				cl = 84;
				cl1 = 105;
			}
			else
			{
				cl = 52;
				cl1 = 84;
			}
		break;
		case 1:
			if (MOD_SKILL_ENEMY_RATE == 10)
			{
				cl = 105;
				cl1 = 125;
			}
			else
			{
				cl = 84;
				cl1 = 105;
			}
		break;
	}
	switch (iNation)
	{
		case "0":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.england);
				if (rShip == true) 
				{	
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.War == true)
					{
						storeArray1[j]= i; 
						j++;
					}
				}
			}				
		break;
		case "1":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.france);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.War == true)
					{
						storeArray1[j]= i; 
						j++;
					}
				}
			}
		break;
		case "2":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.spain);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.War == true)
					{
						storeArray1[j]= i; 
						j++;
					}
				}
			}
		break;
		case "3":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.holland);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.War == true)
					{
						storeArray1[j]= i; 
						j++;
					}
				}
			}
		break;
		case "4":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.pirate);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.War == true)
					{
						storeArray1[j]= i; 
						j++;
					}
				}
			}
		break;
	}
	iType = storeArray1[rand(j-1)];
	ch.Ship.Type = GenerateShipExt(iType, 1, ch);
}
void CreatePGG_Trade(ref ch, int iNation, ref shipOwner)
{
	aref rShip;
	ref rMerch;
	int iType, cl, cl1, i, j;
	ref refShip;
	refShip = GetRealShip(sti(shipOwner.ship.Type));
	int storeArray2[SHIP_TYPES_QUANTITY];
	j = 0;
	
	switch(sti(refShip.Class))
	{
		case 7:
			cl = 3;
			cl1 = 15;
		break;
		case 6:
			cl = 3;
			cl1 = 15;
		break;
		case 5:
			cl = 15;
			cl1 = 28;
		break;
		case 4:
			cl = 28;
			cl1 = 52;
		break;
		case 3:
			cl = 52;
			cl1 = 84;
		break;
		case 2:
			cl = 52;
			cl1 = 84;
		break;
		case 1:
			cl = 52;
			cl1 = 84;
		break;
	}
	i = cl;
	switch (iNation)
	{
		case "0":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.england);
				if (rShip == true) 
				{	
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.Merchant == true)
					{
						storeArray2[j]= i; 
						j++;
					}
				}
			}				
		break;
		case "1":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.france);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.Merchant == true)
					{
						storeArray2[j]= i; 
						j++;
					}
				}
			}
		break;
		case "2":
			for (i;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.spain);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.Merchant == true)
					{
						storeArray2[j]= i; 
						j++;
					}
				}
			}
		break;
		case "3":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.holland);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.Merchant == true)
					{
						storeArray2[j]= i; 
						j++;
					}
				}
			}
		break;
		case "4":
			for (i=cl;i<cl1;i++)
			{
				makearef(rShip,ShipsTypes[i].nation.pirate);
				if (rShip == true) 
				{
					makeref(rMerch,ShipsTypes[i]);			
					if(rMerch.Type.Merchant == true)
					{
						storeArray2[j]= i; 
						j++;
					}
				}
			}
		break;
	}
	iType = storeArray2[rand(j-1)];

	ch.Ship.Type = GenerateShipExt(iType, 1, ch);
	ch.Ship.Mode = "merchant";
}