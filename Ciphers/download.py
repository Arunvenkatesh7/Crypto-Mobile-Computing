import yt_dlp

def download_youtube_playlist(playlist_url, download_path):
    ydl_opts = {
        'outtmpl': f'{download_path}/%(title)s.%(ext)s',
        'format': 'bestvideo[height=720]+bestaudio/best',
        'merge_output_format': 'mp4',
        'noplaylist': False,  # To ensure the entire playlist is downloaded
    }

    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([playlist_url])

if __name__ == "__main__":
    # Example playlist URL
    playlist_url = 'https://www.youtube.com/playlist?list=PL5G1LkxtRqlYcX0J_f_7Jdz5ihEputZFp'
    # Directory where you want to save the downloaded videos
    download_path = r'D:\Projects\ML_AI'

    download_youtube_playlist(playlist_url, download_path)
