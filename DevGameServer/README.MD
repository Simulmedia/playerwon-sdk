# PlayerWON Example Game Server
This game server is meant to be run with the PlayerWON SDK, or a game under development that doesn't have a server yet. It supports a `/login` endpoint which uses the configured PlayerWON API credentials to fetch a new `Access Token`, which should be passed to the game client for each player starting the game.

In a production game, the `/token` API call, in this example, would be hosted by your game server.

## Setup before running
To run, the game server requires the following environment variables to be set:
- `PORT` (optional - default is a random empty port)
- `CLIENT_ID`
- `CLIENT_SECRET`
- `GAMETITLE_ID`

### Windows
`set PORT=1122`

### Unix-like
`export PORT=1122`

## Running the server
Run one of the binaries in `/bin`. Supported platforms are:
- Windows 10/11
- Linux
- MacOS

## Endpoints
<table>
  <tr>
   <th>Endpoint</th>
   <th>Description</th>
   <th>Notes</th>
  </tr>
  <tr>
   <td><code>POST http://localhost:{PORT}/login/{user_id}</code></td>
   <td>Returns an Access Token string or an error string.</td>
   <td>In the PlayerWON backend, we refer to the `{user_id}` value as "IDFA" (Identification For Advertisers).</td>
  </tr>
</table>
