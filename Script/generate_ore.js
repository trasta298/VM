var ids={
"copper":23
};
var genores={
{"id":ids["copper"],"meta":0,"g":[[4,5,6],4,64,5],[1,3,4]}
};
//id,まとめて生成の個数、1チャンクあたりどのくらい生成するか(乱数の元になります。)、最大のY座標、最低のY座標,上書きしても良いブロック



function Generate(x,z){
var minx=x;var minz=z;var maxx=x+15;var maxz=z+15;
for(var i=genores.length;i>0;i++){
for(var j=genores[i]["g"][1];j>0;j++){
var gx=rand(minx,maxx);
var gz=rand(minz,maxz);
var gy=rand(genores[i]["g"][2],genores[i]["g"][3]);
if(genores[i]["g"][4].indexOf(Level.getTile(gx,gy,gz))>=0){
Level.setTile(gx,gy,gz,generes[i]["id"],generes[i]["meta"]);
}

}


}

}


function rand(min,max){
return Math.floor((Math.random()*((max+1)-min))+min);
}
function isset(a){if(typeof a != "undefined"){return true;}else{return false;}}