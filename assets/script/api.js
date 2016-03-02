/*

ブロックレンダラーを弄る関数追加
アドオンを入れることで使えるようにする予定




render = {
	id : {
		[
			[0,0,0,0.5,0.5,0.5],
			[0,0.5,0,0.5,1.0,0.5]
		]
	}
};

*/

Block.setRender = function(render){
	var path=android.os.Environment.getExternalStorageDirectory().getPath()+"/games/com.mojang/Render/";
	java.io.File(path).mkdirs();
	var newFile=new java.io.File(path,"render.render");
	newFile.createNewFile();
	var outWrite=new java.io.OutputStreamWriter(new java.io.FileOutputStream(newFile));
	JSON.stringify(render);
	outWrite.append(render);
	outWrite.close();
}