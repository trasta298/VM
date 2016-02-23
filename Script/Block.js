



function Block(x,y,z){
	this.x = x;
	this.y = y;
	this.z = z;
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

Block.prototype.getPower = function(){
	return this.power;
}