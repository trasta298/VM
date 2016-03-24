//実際にblに適用するファイル
//ソースをダウンロードするコード書く

print("hello variable manufacture!");

function vm() {
    this.loadsource = function () {
    }
    this.download = function (url) {
        var httpGet = new org.apache.http.client.methods.HttpGet(url);
        var httpClient = new org.apache.http.impl.client.DefaultHttpClient();
        httpGet.setHeader("Connection", "Keep-Alive");
        var response = httpClient.execute(httpGet);
        var status = response.getStatusLine().getStatusCode();
        if (status != org.apache.http.HttpStatus.SC_OK) {
            return false;
        } else {
            var receive = org.apache.http.util.EntityUtils.toString(response.getEntity(), "UTF-8");
            return receive;
        }
    }
}

