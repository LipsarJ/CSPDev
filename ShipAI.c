// boal AI компа -->
    if (!bIsCompanion) //fix 171204 boal Не нужно наших с толку сбивать
    {
        string sGroupID = Ship_GetGroupID(rCharacter);
		//Lipsar --->ИИ сторожей
		if(CheckAttribute(rCharacter, "fortDefender") && sti(rCharacter.fortDefender) == 1 && bSeaActive && rCharacter.SeaAI.Task == "3")
		{
			string defGroupID = rCharacter.SeaAI.Task.Target;
			ref attckChar;
			ref fortChar = &characters[sti(rCharacter.SeaAI.Task.Target)];
			if (pchar.Ship.LastBallCharacter != -1 && GetNationRelation2MainCharacter(sti(rCharacter.nation)) == RELATION_ENEMY && sti(rCharacter.SeaAI.Task.Target) != GetMainCharacterIndex()) 
			{
				sTemp = Ship_GetGroupID(&characters[sti(pchar.Ship.LastBallCharacter)]); 
				if (HasSubStr(sTemp,"IslandGroup") || HasSubStr(sTemp,"Fort_"))
				{
					Group_SetEnemyToCharacter(sGroupID, GetMainCharacterIndex());
					SetCharacterRelationBoth(sti(rCharacter.index), GetMainCharacterIndex(), RELATION_ENEMY);
					Group_SetTaskAttack(sGroupID, PLAYER_GROUP);
					Group_LockTask(sGroupID);
					DoQuestCheckDelay("NationUpdate", 0.5);
					return;
				}
			}
			if (sti(rCharacter.Ship.LastBallCharacter) != -1 || CheckAttribute(fortChar,"Ship.LastBallCharacter")) 
			{
				if (sti(rCharacter.Ship.LastBallCharacter) != -1) attckChar = &characters[sti(rCharacter.Ship.LastBallCharacter)];
				else attckChar = CharacterFromId(fortChar.Ship.LastBallCharacter);
				if (attckChar.Ship.LastBallCharacter == defGroupID && GetNationRelation2Character(sti(rCharacter.nation), GetCharacterIndex(attckChar.id)) == RELATION_ENEMY && sti(rCharacter.SeaAI.Task.Target) != GetCharacterIndex(attckChar.id)) 
				{
					Group_SetEnemyToCharacter(sGroupID, GetMainCharacterIndex());
					SetCharacterRelationBoth(sti(rCharacter.index), GetMainCharacterIndex(), RELATION_ENEMY);
					Group_SetTaskAttack(sGroupID, PLAYER_GROUP);
					rCharacter.SeaAI.Task = AITASK_ATTACK;
					Group_LockTask(sGroupID);
					DoQuestCheckDelay("NationUpdate", 0.5);
					return;
				}
				if (GetNationRelation2Character(sti(rCharacter.nation), GetCharacterIndex(attckChar.id)) == RELATION_ENEMY && sti(rCharacter.SeaAI.Task.Target) != GetCharacterIndex(attckChar.id))
				{
					Group_SetEnemyToCharacter(sGroupID, GetCharacterIndex(attckChar.id));
					Group_SetTaskAttack(sGroupID, Ship_GetGroupID(attckChar));
					Group_LockTask(sGroupID);
					rCharacter.SeaAI.Task = AITASK_ATTACK;
					DoQuestCheckDelay("NationUpdate", 0.5);
					rCharacter.SeaAI.Task.Target = GetCharacterIndex(attckChar.id);
					return;
				}
			}
			if(CheckAttribute(pchar, "point"))
			{
				Group_SetEnemyToCharacter(sGroupID, GetMainCharacterIndex());
				SetCharacterRelationBoth(sti(rCharacter.index), GetMainCharacterIndex(), RELATION_ENEMY);
				Group_SetTaskAttack(sGroupID, PLAYER_GROUP);
				Group_LockTask(sGroupID);
				DoQuestCheckDelay("NationUpdate", 0.5);
				DeleteAttribute(pchar, "point");
				return;
			}
		}//<---Lipsar ИИ сторожей