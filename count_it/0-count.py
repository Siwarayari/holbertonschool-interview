#!/usr/bin/python3
"""function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, after="", counts={}):
    """function that queries the Reddit API"""

    response = requests.get("https://www.reddit.com/r/" + subreddit +
                            "/hot.json?after=" + after,
                            headers={'User-Agent': 'count'})

    if response.status_code != 200:
        return None

    data = response.json()
    posts = data['data']['children']

    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            if word in title:
                if word in counts:
                    counts[word] += 1
                else:
                    counts[word] = 1

    after = data['data']['after']

    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word in sorted_counts:
            print("{}: {}".format(word[0], word[1]))
