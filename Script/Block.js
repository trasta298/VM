
var blocks = [];


function Block(x,y,z,dimension){
	this.x = x;
	this.y = y;
	this.z = z;
	this.dimension = dimension;
	this.power = 0;
	
	/*  メソッド一覧
	
	getX();
		x座標
	getY();
		y座標
	getZ();
		z座標
	getPower();
		電力
	getDimension();
		ディメンション
	SetMachineBlock(x,y,z,id,side);
		void
	
	*/
}

Block.prototype.getX = function(){
	return this.x;
}

Block.prototype.getY = function(){
	return this.y;
}

Block.prototype.getZ = function(){
	return this.z;
}

Block.prototype.getDimension = function(){
	return this.dimension;
}

Block.prototype.getPower = function(){
	return this.power;
}

//追加工業ブロック設置関数
Block.prototype.SetMachineBlock = function(x,y,z,id,side){
	preventDefault();
	switch(side){
		case 0:y-=1;break;
		case 1:y+=1;break;
		case 2:z-=1;break;
		case 3:z+=1;break;
		case 4:x-=1;break;
		case 5:x+=1;break;
	}
	var dmg=0;
	var rm=Entity.getYaw(Player.getEntity())%360;
	if(rm<-315||-45<=rm&&rm<45) dmg=1;
	else if(-315<=rm&&rm<-225||45<=rm&&rm<135) dmg=3;
	else if(-225<=rm&&rm<-135||135<=rm&&rm<225) dmg=0;
	else if(-135<=rm&&rm<-45||225<=rm) dmg=2;
	setTile(x,y,z,id,dmg);
	Level.playSound(x,y,z,"step.stone",3,10);
	if(Level.getGameMode()==0){
		count = Player.getCarriedItemCount();
		if(count==1) Entity.setCarriedItem(getPlayerEnt(),0,0,0);
		else Entity.setCarriedItem(getPlayerEnt(),id,count-1,dmg);
	}
	return {x:x,y:y,z:z};
}